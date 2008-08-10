# New ports collection makefile for:	Metalink tools
# Date created:		Sun 10 Aug 2008 04:22:51 UTC
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	metalink
PORTVERSION=	0.3.3
CATEGORIES=	misc
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	metalinks
PKGNAMESUFFIX?=	-tools

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Metalink generation tool

LIB_DEPENDS=	gcrypt.15:${PORTSDIR}/security/libgcrypt \
		boost_filesystem.4:${PORTSDIR}/devel/boost \
		boost_program_options.4:${PORTSDIR}/devel/boost \
		boost_regex.4:${PORTSDIR}/devel/boost

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	AWK="${AWK}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

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
