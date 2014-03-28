# Created by: Peter Czanik <czanik@balabit.hu>
# $FreeBSD$

PORTNAME=	syslog-ng-incubator
PORTVERSION=	0.2.1
CATEGORIES=	sysutils
DISTFILES=	syslog-ng-incubator-${PORTVERSION}.tar.xz
MASTER_SITES=	http://packages.madhouse-project.org/syslog-ng/incubator/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The syslog-ng module incubator

WRKSRC=		$(WRKDIR)/$(PORTNAME)-$(PORTVERSION)

MAKE_JOBS_UNSAFE=	yes

LIB_DEPENDS=	libevtlog.so:${PORTSDIR}/sysutils/eventlog
LIB_DEPENDS=	libsyslog-ng-3.5.4.1.so:${PORTSDIR}/sysutils/syslog-ng-devel

USES=           gmake pkgconfig pathfix bison lua tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_AUTOTOOLS=	autoconf:env

CONFIGURE_ARGS=	--datadir=${PREFIX}/share/syslog-ng/

.include <bsd.port.pre.mk>

USE_LUA=	5.1+

.include <bsd.port.post.mk>
