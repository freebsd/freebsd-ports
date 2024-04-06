PORTNAME=	check_mysql_health
DISTVERSION=	3.0.0.5
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	https://labs.consol.de/assets/downloads/nagios/

MAINTAINER=	kirill@varnakov.com
COMMENT=	Nagios plugin to check various parameters of a MySQL database
WWW=		https://labs.consol.de/de/nagios/check_mysql_health/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${DBD_MYSQL}

USES=		autoreconf mysql perl5 gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-statefiles-dir=${NAGIOSDIR} \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-mymodules-dir=${PREFIX}/libexec/nagios \
		--with-mymodules-dyn-dir=${PREFIX}/libexec/nagios \
		--libexecdir=${PREFIX}/libexec/nagios \
		--with-perl=${PERL}

NO_ARCH=	yes

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

PLIST_FILES=	libexec/nagios/check_mysql_health

.include <bsd.port.mk>
