# New ports collection makefile for:   dieharder
# Date created:        14 November 2008
# Whom:                bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	dieharder
DISTVERSION=	3.29.4beta
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.phy.duke.edu/~rgb/General/dieharder/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A random number generator testsuite

LIB_DEPENDS=	gsl:${PORTSDIR}/math/gsl

MAKE_JOBS_UNSAFE=	yes

USE_DOS2UNIX=	yes
USE_AUTOTOOLS=	aclocal:110 autoheader:262 libtool:22
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes
MAN1=		dieharder.1
MAN3=		libdieharder.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64 or sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|./configure|#./configure|g" \
		${WRKSRC}/autogen.sh

run-autotools:
	(cd ${WRKSRC}; ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -ifv)
	@${REINPLACE_CMD} -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
		-e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
			${WRKSRC}/configure

test: build
	${WRKSRC}/dieharder/dieharder -a

.include <bsd.port.post.mk>
