# Created by: Peter Czanik <czanik@balabit.hu>
# $FreeBSD$

PORTNAME=	syslog-ng-incubator
PORTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/balabit/syslog-ng-incubator/releases/download/syslog-ng-incubator-${PORTVERSION}/
# http://packages.madhouse-project.org/syslog-ng/incubator/
DISTFILES=	syslog-ng-incubator-${PORTVERSION}.tar.xz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The syslog-ng module incubator

WRKSRC=		$(WRKDIR)/$(PORTNAME)-$(PORTVERSION)

MAKE_JOBS_UNSAFE=	yes

LIB_DEPENDS=	libevtlog.so:${PORTSDIR}/sysutils/eventlog \
		libsyslog-ng-3.6.so.0:${PORTSDIR}/sysutils/syslog-ng

USES=		gmake pkgconfig pathfix bison lua tar:xz libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_AUTOTOOLS=	autoconf:env

CONFIGURE_ARGS=	--datadir=${PREFIX}/share/syslog-ng/ --disable-java

.include <bsd.port.mk>
