# New ports collection makefile for:   synce-gnomevfs
# Date created:                28 August 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	synce-gvfs
PORTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	palm
MASTER_SITES=	SF/synce/SynCE-GNOME/0.14

MAINTAINER=	avl@FreeBSD.org
COMMENT=	GVFS module for access Windows Mobile devices

EXTRACT_DEPENDS=${NONEXISTENT}:${GVFS_PORTDIR}:patch
LIB_DEPENDS=	rapi.2:${PORTSDIR}/palm/synce-librapi2

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack gvfs
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

GVFS_PORTDIR=	${PORTSDIR}/devel/gvfs
GVFS_WRKSRC_CMD=cd ${GVFS_PORTDIR} && ${MAKE} -V WRKSRC


post-extract:
.for dir in common daemon
	${CP} `${GVFS_WRKSRC_CMD}`/${dir}/*.[ch] ${WRKSRC}/gvfs/${dir}
.endfor

.include <bsd.port.mk>
