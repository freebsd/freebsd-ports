PORTNAME=	check_nwc_health
PORTVERSION=	11.2.4
CATEGORIES=	net-mgmt
MASTER_SITES=	https://labs.consol.de/assets/downloads/nagios/

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Nagios plugin to monitor network equipment via SNMP
WWW=		https://labs.consol.de/nagios/check_nwc_health

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-JSON-XS>=4.0:converters/p5-JSON-XS \
		p5-JSON>=4.0:converters/p5-JSON

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
