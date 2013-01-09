# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxul
DISTVERSION=	10.0.12
CATEGORIES?=	www devel
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	firefox/releases/${DISTVERSION}esr/source
DISTNAME=	firefox-${DISTVERSION}esr.source

MAINTAINER?=	gecko@FreeBSD.org
COMMENT?=	Mozilla runtime package that can be used to bootstrap XUL+XPCOM apps

BUILD_DEPENDS=	nspr>=4.8.8:${PORTSDIR}/devel/nspr \
		nss>=3.13.6_1:${PORTSDIR}/security/nss \
		sqlite3>=3.7.7.1:${PORTSDIR}/databases/sqlite3 \
		cairo>=1.10.2_1,1:${PORTSDIR}/graphics/cairo \
		unzip:${PORTSDIR}/archivers/unzip

WRKSRC=		${WRKDIR}/mozilla-esr10
CONFLICTS=	mozilla-[0-9]* libxul-1.9.*

USE_AUTOTOOLS=	autoconf213:env
WANT_GNOME=	yes
USE_QT4=	# empty
QT_NONSTANDARD=	yes
WANT_PERL=	yes
ALL_TARGET=	default
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		gl
MAKE_JOBS_SAFE=	yes
MAKE_ENV=	SKIP_GRE_REGISTRATION=1 mozappdir=${PREFIX}/lib/${MOZILLA}
LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}
USE_LDCONFIG=	${PREFIX}/lib/${MOZILLA}

MOZ_OPTIONS?=	--enable-application=xulrunner
MOZ_EXTENSIONS=	default,cookie,permissions
USE_GECKO=	gecko
MOZILLA_EXEC_NAME=xulrunner
USE_MOZILLA=	# empty
MOZILLA_PLIST_DIRS=	bin include lib share/idl
PLIST_DIRSTRY=	share/idl
MOZ_PKGCONFIG_FILES=	libxul-embedding libxul mozilla-js \
			mozilla-plugin

OPTIONS_DEFAULT=GIO

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.pre.mk>

.if ${USE_MOZILLA:M-nss}
MOZ_PKGCONFIG_FILES+=	mozilla-nss
.endif

.if ${ARCH} == amd64
CONFIGURE_TARGET=x86_64-portbld-freebsd${OSREL}
.elif ${ARCH} == powerpc64
.if ${OSVERSION} < 900033
BROKEN=		Needs binutils 2.17.50 to build
.else
MOZ_EXPORT+=	UNAME_m="powerpc64"
CFLAGS+=	-mminimal-toc
.endif
.endif

.if !empty(CXX:M*clang++*) || (${CXX:Mc++} && ${OSVERSION} > 1000023)
CXXFLAGS+=	-Wno-return-type-c-linkage
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/xulrunner/stub/nsXULStub.cpp

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${WRKSRC}/js/src/ && ${AUTOCONF})

post-build:
	@${REINPLACE_CMD} -e "s|\(Libs:.*\)\($$\)|\1 -Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}\2| ; \
		s|%sdkdir%|%sdkdir%/sdk|g ; \
		s|%%MOZ_LIBDIR%%|${PREFIX}/lib/${MOZILLA}|g" \
		${WRKSRC}/xulrunner/installer/*.pc.in || ${TRUE}

.include <bsd.port.post.mk>
