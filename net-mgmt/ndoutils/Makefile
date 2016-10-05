# $FreeBSD$

PORTNAME=	ndoutils
PORTVERSION=	2.1.0
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/nagios/${PORTNAME}-2.x/${PORTNAME}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Keep Nagios perfdata in MySQL database

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include -fPIC
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/ndoutils \
			--localstatedir=/var/run --enable-mysql \
			--with-mysql=${LOCALBASE}

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS NANOSLEEP
OPTIONS_SINGLE=		NAGIOS_BACKEND
OPTIONS_SINGLE_NAGIOS_BACKEND=	NAGIOS3X NAGIOS4X
OPTIONS_DEFAULT=	NAGIOS3X NANOSLEEP
NAGIOS3X_DESC=		For Nagios 3.X Series
NAGIOS4X_DESC=		For Nagios 4.X Series
NANOSLEEP_DESC=		Use of nanosleep in event timing
NAGIOS3X_RUN_DEPENDS=	${LOCALBASE}/bin/nagios:net-mgmt/nagios
NAGIOS4X_RUN_DEPENDS=	${LOCALBASE}/bin/nagios:net-mgmt/nagios4
NANOSLEEP_CONFIGURE_ENABLE=	nanosleep

USES=		mysql perl5
USE_RC_SUBR=	ndo2db
SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/file2sock ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/log2ndo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/sockdebug ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/db && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/)
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/nagios
	${INSTALL_DATA} ${WRKSRC}/config/misccommands.cfg ${STAGEDIR}${PREFIX}/etc/nagios/misccommands.cfg-sample
	${INSTALL_DATA} ${WRKSRC}/config/nagios.cfg ${STAGEDIR}${PREFIX}/etc/nagios/ndoutils.cfg-sample
	${INSTALL_DATA} ${WRKSRC}/config/ndo2db.cfg-sample ${STAGEDIR}${PREFIX}/etc/nagios/ndo2db.cfg-sample
	${INSTALL_DATA} ${WRKSRC}/config/ndomod.cfg-sample ${STAGEDIR}${PREFIX}/etc/nagios/ndomod.cfg-sample

do-install-NAGIOS3X-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ndo2db-3x ${STAGEDIR}${PREFIX}/bin/ndo2db
	${INSTALL_PROGRAM} ${WRKSRC}/src/ndomod-3x.o ${STAGEDIR}${PREFIX}/bin/ndomod.o

do-install-NAGIOS4X-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ndo2db-4x ${STAGEDIR}${PREFIX}/bin/ndo2db
	${INSTALL_PROGRAM} ${WRKSRC}/src/ndomod-4x.o ${STAGEDIR}${PREFIX}/bin/ndomod.o

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.mk>
