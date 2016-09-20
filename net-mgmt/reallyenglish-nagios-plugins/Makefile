# $FreeBSD$

PORTNAME=	reallyenglish-nagios-plugins
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://journal.reallyenglish.com/

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Nagios plugins at reallyenglish

RUN_DEPENDS+=	${LOCALBASE}/libexec/nagios/utils.sh:${PORTSDIR}/net-mgmt/nagios-plugins \
	p5-Nagios-Plugin>=0:${PORTSDIR}/net-mgmt/p5-Nagios-Plugin \
	amrstat:${PORTSDIR}/sysutils/amrstat \
	cciss_vol_status:${PORTSDIR}/sysutils/cciss_vol_status

NO_BUILD=	Yes

USES=	tar:tgz shebangfix

SHEBANG_FILES=	src/check_raid_amrstat/check_raid_amrstat \
				src/check_mpt/check_mpt

.include <bsd.port.pre.mk>

# XXX this should be fixed in the upstream
pre-install:
	${INSTALL} -d ${STAGEDIR}${PREFIX}/libexec/nagios
	${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} \
                -e 's/$${ECHO} /echo /g'

do-install:
	${MAKE} -C ${WRKSRC} install DESTDIR=${STAGEDIR}${PREFIX}

.include <bsd.port.post.mk>
