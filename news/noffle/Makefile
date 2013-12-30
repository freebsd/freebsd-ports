# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	noffle
PORTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28devel%29/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	News server for low speed dial-up connections

LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-configfile=${LOCALBASE}/etc/noffle.conf \
		--with-usersfile=${LOCALBASE}/etc/noffle.users
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

SPOOL_DIR=	/var/spool/noffle
PLIST_SUB+=	SPOOL_DIR=${SPOOL_DIR}

DOCS=		ChangeLog docs/FAQ INSTALL docs/INTERNALS README \
		docs/testing.txt docs/noffle.lsm

post-patch:
	@${REINPLACE_CMD} -e \
	's|/etc/noffle.conf|${PREFIX}/etc/noffle.conf|g' \
		${WRKSRC}/docs/${PORTNAME}.1 \
		${WRKSRC}/docs/${PORTNAME}.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/noffle.1 \
		${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/noffle.conf.5 \
		${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/noffle.conf.example \
		${STAGEDIR}${PREFIX}/etc/noffle.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

post-install:
	${SED} -e "s:/usr/local:${PREFIX}:g" ${PKGMESSAGE}

.include <bsd.port.mk>
