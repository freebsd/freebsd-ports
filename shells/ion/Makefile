PORTNAME=	ion
DISTVERSION=	1.0.5-1509
DISTVERSIONSUFFIX=	g85452cfa
PORTREVISION=	10
CATEGORIES=	shells
PKGNAMESUFFIX=	-shell

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Modern system shell written in Rust
WWW=		https://gitlab.redox-os.org/redox-os/ion

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITLAB=	yes
GL_SITE=	https://gitlab.redox-os.org
GL_ACCOUNT=	redox-os
GL_TAGNAME=	85452cfa801d11dee1dfe0f787780a4c9285c267

CONFLICTS_INSTALL=	ion

OPTIONS_DEFINE=	DOCS EXAMPLES

# liner-0.4.4 does not build with Rust 1.40.0.  Use the newer copy
# that is also already available.
#post-patch:
#	@${REINPLACE_CMD} 's,^liner = .*,liner = \{ git = "https://gitlab.redox-os.org/redox-os/liner" \},' \
#		${WRKSRC_crate_calculate}/Cargo.toml

post-configure:
	${ECHO_CMD} ${GL_TAGNAME} > ${WRKSRC}/git_revision.txt

post-install-DOCS-on:
	@cd ${WRKSRC}/manual/src && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@cd ${WRKSRC}/tests && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
