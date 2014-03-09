# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	uuid
PORTVERSION=	1.6.2
PORTREVISION=	4
CATEGORIES=	misc devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	vd@FreeBSD.org
COMMENT=	ISO-C & Perl API and CLI for generating Universally Unique Identifiers

#CONFLICTS=	e2fsprogs-libuuid-[0-9]*

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-shared --enable-static --with-cxx \
		--includedir=${PREFIX}/include/ossp

.if defined(WITH_PERL)
MAKE_JOBS_UNSAFE=	yes
USES+=		perl5
CONFIGURE_ENV+=	PERL=${PERL5}
CONFIGURE_ARGS+=--with-perl
# Without WITH_PERL=yes in uuid's make args it could pick WITH_PERL=1 if
# somebody has run "make WITH_PERL=1" in the port's directory, then its check
# whether WITH_PERL is set to "yes" would fail.
MAKE_ARGS+=	WITH_PERL=yes
PLIST_SUB+=	WITH_PERL=''
.else
PLIST_SUB+=	WITH_PERL='@comment '
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC -DPIC
.endif

post-patch:
	${REINPLACE_CMD} -e 's/\(libuuid\\*\.\)la/\1a/g' \
		${WRKSRC}/perl/Makefile.PL

regression-test: test

test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.post.mk>
