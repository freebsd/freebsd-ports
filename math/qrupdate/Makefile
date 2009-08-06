# New ports collection makefile for:	qrupdate
# Date created:		4 August 2009
# Whom:			Robert Jenssen
#
# $FreeBSD$
#

PORTNAME=	qrupdate
PORTVERSION=	1.0.1
CATEGORIES=	math
MASTER_SITES=	http://downloads.sourceforge.net/project/qrupdate/qrupdate/1.0/ \
		http://transact.dl.sourceforge.net/project/qrupdate/qrupdate/1.0/

MAINTAINER=	robertjenssen@ozemail.com.au
COMMENT=	Fortran library for fast updates of QR and Cholesky decomposition

FETCH_ARGS=	-p

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

USE_FORTRAN=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

pre-build:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; s+%%FFLAGS%%+${FFLAGS}+g ; \
		s+%%PICFLAG%%+${PICFLAG}+g ; ' \
		${WRKSRC}/Makeconf

.include <bsd.port.post.mk>
