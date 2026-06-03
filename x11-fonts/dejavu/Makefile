PORTNAME=	dejavu
PORTVERSION=	2.37
DISTVERSIONPREFIX=	fonts-ttf-
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/dejavu-fonts/dejavu-fonts/releases/download/version_${PORTVERSION:R}_${PORTVERSION:E}/

PATCH_SITES=	https://github.com/dejavu-fonts/dejavu-fonts/commit/
PATCHFILES=	d9ee532b4f0a879372bdb006ac85d7807629ea98.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bitstream Vera Fonts clone with a wider range of characters
WWW=		https://dejavu-fonts.github.io/

LICENSE=	AMS AREV BITSTREAM
LICENSE_COMB=	multi
LICENSE_NAME_AMS=	AMSFonts Copyright version 2.2
LICENSE_NAME_AREV=	Arev Fonts Copyright
LICENSE_NAME_BITSTREAM=	Bitstream Vera Fonts Copyright
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS_AMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell
LICENSE_PERMS_AREV=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell
LICENSE_PERMS_BITSTREAM=auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

USES=		fonts tar:bzip2

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_SUB=	FCDIR=${FCDIR} FCDIR_LINKS=${FCDIR_LINKS}
PORTDOCS=	README.md langcover.txt status.txt unicover.txt

FCDIR?=		etc/fonts/conf.avail
FCDIR_LINKS=	${FCDIR:S|conf.avail|conf.d|}

OPTIONS_DEFINE=	DOCS LINKS
OPTIONS_DEFAULT=LINKS
OPTIONS_SUB=	yes
LINKS_DESC=	Install links of configuration files in conf.d

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FCDIR}/ ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/fontconfig/*.conf ${STAGEDIR}${PREFIX}/${FCDIR}/
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${STAGEDIR}${FONTSDIR}/

do-install-LINKS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FCDIR_LINKS}/
	cd ${STAGEDIR}${PREFIX}/${FCDIR_LINKS}/ && ${LN} -fs ../conf.avail/*dejavu*.conf .

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
