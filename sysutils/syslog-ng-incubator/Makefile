# Created by: Peter Czanik <czanik@balabit.hu>
# $FreeBSD$

PORTNAME=	syslog-ng-incubator
PORTVERSION=	0.3.3
CATEGORIES=	sysutils
MASTER_SITES=	http://packages.madhouse-project.org/syslog-ng/incubator/
DISTFILES=	syslog-ng-incubator-${PORTVERSION}.tar.xz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The syslog-ng module incubator

BROKEN=		Fails to build with syslog-ng36

WRKSRC=		$(WRKDIR)/$(PORTNAME)-$(PORTVERSION)

MAKE_JOBS_UNSAFE=	yes

LIB_DEPENDS=	libevtlog.so:${PORTSDIR}/sysutils/eventlog \
		libsyslog-ng.so:${PORTSDIR}/sysutils/syslog-ng

USES=		gmake pkgconfig pathfix bison lua tar:xz libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_AUTOTOOLS=	autoconf:env

CONFIGURE_ARGS=	--datadir=${PREFIX}/share/syslog-ng/

.include <bsd.port.mk>
