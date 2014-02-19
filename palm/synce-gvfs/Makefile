# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	synce-gvfs
PORTVERSION=	0.3.1
PORTREVISION=	4
CATEGORIES=	palm
MASTER_SITES=	SF/synce/SynCE-GNOME/0.14

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GVFS module for access Windows Mobile devices

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-10

EXTRACT_DEPENDS=${NONEXISTENT}:${GVFS_PORTDIR}:patch
LIB_DEPENDS=	rapi.2:${PORTSDIR}/palm/synce-librapi2


GNU_CONFIGURE=	yes
USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix gvfs
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

GVFS_PORTDIR=	${PORTSDIR}/devel/gvfs
GVFS_WRKSRC_CMD=cd ${GVFS_PORTDIR} && ${MAKE} -V WRKSRC


NO_STAGE=	yes
post-extract:
.for dir in common daemon
	${CP} `${GVFS_WRKSRC_CMD}`/${dir}/*.[ch] ${WRKSRC}/gvfs/${dir}
.endfor

.include <bsd.port.mk>
