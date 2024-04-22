PORTNAME=	port-maintenance-tools
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	ports-mgmt

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Meta-port for administrative tools to maintain ports

USES=	metaport

.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS=	svn:devel/subversion-lts
.else
RUN_DEPENDS=	svn:devel/subversion
.endif
RUN_DEPENDS+=	\
		${LOCALBASE}/sbin/portupgrade:ports-mgmt/portupgrade \
		${LOCALBASE}/sbin/pkg_cutleaves:ports-mgmt/pkg_cutleaves \
		${LOCALBASE}/bin/pkg_tree:ports-mgmt/pkg_tree \
		${LOCALBASE}/sbin/portdowngrade:ports-mgmt/portdowngrade

.include <bsd.port.mk>
