PORTNAME=	autossh
PORTVERSION=	1.4g
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.harding.motd.ca/autossh/

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Automatically restart SSH sessions and tunnels
WWW=		https://www.harding.motd.ca/autossh/

LICENSE=	BSD3CLAUSE

USES=		tar:tgz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PORTDOCS=	CHANGES README

# Fix build with clang11
CFLAGS+=	-fcommon

OPTIONS_DEFINE=	DOCS SSH_PORTABLE

SSH_PORTABLE_DESC=	Default to ports openssh (instead of base)

SSH_PORTABLE_CONFIGURE_ENV=	ac_cv_path_ssh=${LOCALBASE}/bin/ssh
SSH_PORTABLE_RUN_DEPENDS=	${LOCALBASE}/bin/ssh:security/openssh-portable

.include <bsd.port.mk>
