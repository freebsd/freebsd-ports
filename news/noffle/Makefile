# New ports collection makefile for:	noffle
# Date created:				28.06.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	noffle
PORTVERSION=	1.1.5
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	News server for low speed dial-up connections

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS+=--with-configfile=${LOCALBASE}/etc/noffle.conf \
		--with-usersfile=${LOCALBASE}/etc/noffle.users
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

SPOOL_DIR=	/var/spool/noffle
PLIST_SUB+=	SPOOL_DIR=${SPOOL_DIR}

MAN1=		noffle.1
MAN5=		noffle.conf.5
DOCS=		ChangeLog docs/FAQ INSTALL docs/INTERNALS README \
		docs/testing.txt docs/noffle.lsm

post-patch:
	@${REINPLACE_CMD} -e \
	's|/etc/noffle.conf|${PREFIX}/etc/noffle.conf|g' \
		${WRKSRC}/docs/${PORTNAME}.1 \
		${WRKSRC}/docs/${PORTNAME}.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/noffle.1 \
		${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/noffle.conf.5 \
		${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/noffle.conf.example \
		${PREFIX}/etc/noffle.conf.sample
	@${ECHO} "
	@${ECHO} "------------------------------------------------------------"
	@${ECHO} "Sample of configuration file placed at"
	@${ECHO} "${PREFIX}/etc/noffle.conf.sample"
	@${ECHO} "------------------------------------------------------------
	@${ECHO} "
	@${MKDIR} ${SPOOL_DIR}
	@${MKDIR} ${SPOOL_DIR}/data
	@${MKDIR} ${SPOOL_DIR}/lock
	@${MKDIR} ${SPOOL_DIR}/outgoing
	@${MKDIR} ${SPOOL_DIR}/overview
	@${MKDIR} ${SPOOL_DIR}/requested
	@${CHOWN} -R news:news ${SPOOL_DIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

post-install:
	@${SED} -e "s:/usr/local:${PREFIX}:g" ${PKGMESSAGE}

.include <bsd.port.mk>
