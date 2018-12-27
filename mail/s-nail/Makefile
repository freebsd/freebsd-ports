# $FreeBSD$

PORTNAME=	s-nail
PORTVERSION=	14.9.11
CATEGORIES=	mail
MASTER_SITES=	https://www.sdaoden.eu/downloads/

MAINTAINER=	yasu@utahime.org
COMMENT=	Send and receive Internet mail

LICENSE=		BSD3CLAUSE BSD4CLAUSE ISCL MIT RFC2104 RSA
LICENSE_COMB=		multi
LICENSE_NAME_RFC2104=	License of RFC2104
LICENSE_NAME_RSA=	RSA Data Security license
LICENSE_FILE=		${WRKSRC}/COPYING
LICENSE_PERMS_RFC2104=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_RSA=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libidn2.so:dns/libidn2
RUN_DEPENDS=	mime-support>0:misc/mime-support

USES=		iconv ssl tar:xz

PLIST_FILES=	bin/s-nail \
		"@sample etc/s-nail.rc.sample" \
		libexec/s-nail-privsep \
		man/man1/s-nail.1.gz

MAKEFILE=	makefile
MAKE_ENV=	VAL_PREFIX=${PREFIX} VAL_MANDIR=${MANPREFIX}/man VAL_MIME_TYPES_SYS=${PREFIX}/etc/mime.types VAL_IDNA=idn2
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/nail.rc ${STAGEDIR}${PREFIX}/etc/s-nail.rc.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
