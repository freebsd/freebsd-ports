# Created by: Oliver Eikemeier
# $FreeBSD$

PORTNAME=	tenshi
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	sysutils
PATCH_SITES=	https://github.com/f-secure-foundry/tenshi/commit/
PATCHFILES=	1c9c887.patch:-p1 \
		50f7660.patch:-p1

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Log monitoring program, designed to watch multiple logs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-IO-BufferedSelect>=0:devel/p5-IO-BufferedSelect

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	f-secure-foundry
USE_PERL5=	run
USE_RC_SUBR=	tenshi
SHEBANG_FILES=	tenshi

MAKE_ARGS=	bindir="${PREFIX}/sbin" \
		docdir="${DOCSDIR}" \
		mandir="${MAN8PREFIX}/share/man" \
		sysconfdir="${PREFIX}/etc"

NO_ARCH=	yes
NO_BUILD=	yes
SUB_LIST=	PERL="${PERL}"

USERS=		tenshi
GROUPS=		tenshi

PLIST_FILES=	'@dir /var/lib' \
		'@dir(tenshi,tenshi,755) /var/lib/tenshi' \
		'@sample ${ETCDIR}/tenshi.conf.sample' \
		sbin/tenshi \
		share/man/man8/tenshi.8.gz

PORTDOCS=	Changelog README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/tenshi/tenshi.conf|${ETCDIR}/tenshi.conf|" \
		${WRKSRC}/tenshi

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/LICENSE
	@(cd ${STAGEDIR}${ETCDIR} && ${MV} tenshi.conf tenshi.conf.sample)

.include <bsd.port.mk>
