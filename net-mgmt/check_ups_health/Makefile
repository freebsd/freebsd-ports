# $FreeBSD$

PORTNAME=	check_ups_health
PORTVERSION=	2.9.2.4
CATEGORIES=	net-mgmt
MASTER_SITES=	https://labs.consol.de/assets/downloads/nagios/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Nagios plugin to check various UPS systems

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5
NO_ARCH=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-statefiles-dir=${NAGIOSDIR} \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-mymodules-dir=${PREFIX}/libexec/nagios \
		--with-mymodules-dyn-dir=${PREFIX}/libexec/nagios \
		--libexecdir=${PREFIX}/libexec/nagios \
		--with-perl=${PERL}

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

PLIST_FILES=	libexec/nagios/check_ups_health

post-patch:
	${REINPLACE_CMD} -e "s| /bin/sed| ${SED}|" -e "s| /bin/grep| ${GREP}|" \
	    ${WRKSRC}/plugins-scripts/Makefile.in

.include <bsd.port.mk>
