# New ports collection makefile for:		lam
# Date created:					Aug 21 2001
# Whom:						bremner@unb.ca
#
# $FreeBSD$
#

PORTNAME=      	lam
PORTVERSION=   	6.5.9
CATEGORIES=    	net parallel
MASTER_SITES=  	http://www.lam-mpi.org/download/files/

MAINTAINER=    	bremner@unb.ca
COMMENT=	Local Area Multicomputer MPI implementation

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-rsh=ssh

CONFLICTS=	lam-7.*

.include "files/manpages"

.include <bsd.port.mk>
