# $FreeBSD$

PORTNAME=	check_mysql_health
PORTVERSION=	2.2.1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://labs.consol.de/assets/downloads/nagios/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plugin to check various parameters of a MySQL database

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-statefiles-dir=${NAGIOSDIR} \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-mymodules-dir=${PREFIX}/libexec/nagios \
		--with-mymodules-dyn-dir=${PREFIX}/libexec/nagios \
		--libexecdir=${PREFIX}/libexec/nagios \
		--with-perl=${PERL}

USES=		perl5
NO_ARCH=	yes

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

PLIST_FILES=	libexec/nagios/check_mysql_health

.include <bsd.port.mk>
