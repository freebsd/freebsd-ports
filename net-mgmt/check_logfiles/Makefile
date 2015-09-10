# $FreeBSD$

PORTNAME=	check_logfiles
PORTVERSION=	3.7.1.1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://labs.consol.de/assets/downloads/nagios/

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Nagios plugin which scans log files for specific patterns

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake perl5
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=	--with-trusted-path=/bin:/sbin:/usr/bin:/usr/sbin:${LOCALBASE}/bin:${LOCALBASE}/sbin \
			--libexecdir=${PREFIX}/libexec/nagios \

.include <bsd.port.mk>
