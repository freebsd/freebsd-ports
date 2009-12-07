# New ports collection makefile for:	ruby-mpi
# Date created:		2005 Apr 24
# Whom:			mneumann@ntecs.de
#
# $FreeBSD$
#

PORTNAME=	mpi
PORTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	net ruby
MASTER_SITES=	SF/${PORTNAME}ruby/${PORTNAME}ruby/${PORTNAME}ruby-${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding of MPI (Message Passing Interface)

BUILD_DEPENDS=	${LOCALBASE}/lib/libmpich.a:${PORTSDIR}/net/mpich2
RUN_DEPENDS=	${LOCALBASE}/lib/libmpich.a:${PORTSDIR}/net/mpich2

USE_BZIP2=	yes
USE_RUBY=	yes
HAS_CONFIGURE=	yes

MAN1=		mpi_ruby.1
MAN3=		MPI_Comm.3 MPI_Exception.3 MPI_Group.3 MPI_Keyval.3 MPI_Op.3 MPI_Request.3 \
		MPI_Ruby.3 MPI_Status.3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mpi_ruby ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/*.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/man3/*.3 ${PREFIX}/man/man3
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${MKDIR} ${RUBY_MODDOCDIR}
	${MKDIR} ${RUBY_MODDOCDIR}/html
	${MKDIR} ${RUBY_MODDOCDIR}/rd

	${CP} ${WRKSRC}/examples/*.rb ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README ${WRKSRC}/docs/MPI \
		${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/docs/html/*.html ${RUBY_MODDOCDIR}/html/
	${INSTALL_DATA} ${WRKSRC}/docs/rd/*.rd ${RUBY_MODDOCDIR}/rd/
.endif

.include <bsd.port.mk>
