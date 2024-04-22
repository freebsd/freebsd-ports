PORTNAME=	port-authoring-tools
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	ports-mgmt

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	"meta-port" for tools to test and submit changes to ports

USES=	metaport
# note: portlint is brought in by porttools
.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS=	svn:devel/subversion-lts
.else
RUN_DEPENDS=	svn:devel/subversion
.endif
RUN_DEPENDS+=	\
		${LOCALBASE}/sbin/libchk:sysutils/libchk \
		${LOCALBASE}/bin/port:ports-mgmt/porttools

.include <bsd.port.mk>
