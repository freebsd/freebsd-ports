# New ports collection makefile for:	Metalink tools
# Date created:		Sun 10 Aug 2008 04:22:51 UTC
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	metalink
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}s/Metalink%20commandline/${PORTVERSION}
PKGNAMESUFFIX?=	-tools

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Metalink generation tool

LIB_DEPENDS=	gcrypt.16:${PORTSDIR}/security/libgcrypt \
		boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		boost_program_options.4:${PORTSDIR}/devel/boost-libs \
		boost_regex.4:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	AWK="${AWK}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

# Documents to install
DOC_FILES=	\
		README

.ifndef(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_FILES=	bin/${PORTNAME}

do-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
