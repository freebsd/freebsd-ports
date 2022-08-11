PORTNAME=	check_nwc_health
PORTVERSION=	10.2.1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://labs.consol.de/assets/downloads/nagios/

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Nagios plugin to monitor network equipment via SNMP

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	perl5

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-perl=${PERL}

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
USERS=		${NAGIOSUSER}
GROUPS=		${NAGIOSGROUP}

PLIST_FILES=	libexec/check_nwc_health

post-patch:
	${REINPLACE_CMD} -e "s| /bin/sed| ${SED}|" -e "s| /bin/grep| ${GREP}|" \
	    ${WRKSRC}/plugins-scripts/Makefile.in
	# Remove unused expression that is problematic for pkg-fallout
	# under 12.3 but causes no problems anywhere else
	${REINPLACE_CMD} -e "/@AWK@/d" ${WRKSRC}/plugins-scripts/subst.in

.include <bsd.port.mk>
