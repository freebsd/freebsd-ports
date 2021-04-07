PORTNAME=	pine-pgp-filters
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	mail security
MASTER_SITES=	LOCAL/marino
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mbeis@xs4all.nl
COMMENT=	Simple sh-based filters to use GnuPG with Alpine

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gpg2:security/gnupg
RUN_DEPENDS=	alpine:mail/alpine \
		gpg2:security/gnupg

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
NO_ARCH=	yes

PORTDOCS=	BUGS CHANGES INSTALL README
PLIST_FILES=	bin/ppf_mime bin/ppf_mime_decrypt \
		libexec/ppf_decrypt libexec/ppf_encrypt libexec/ppf_mime \
		libexec/ppf_mime_decrypt libexec/ppf_sign libexec/ppf_verify

OPTIONS_DEFINE=	DOCS

DOCS_SUB_FILES=	pkg-message

verify:	checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
