PORTNAME=	syntax-highlighting
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	textproc kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 syntax highlighting engine for structured text and code

USES=		cmake compiler:c++11-lib kde:5 perl5 qt:5 tar:xz
USE_KDE=	ecm:build
# Use hybrid ABI Perl
USE_PERL5=	run build pkg64
USE_QT=		core gui network \
		buildtools:build linguisttools:build testlib:build qmake:build

CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5XmlPatterns=TRUE

.include <bsd.port.pre.mk>

.if ${ABI:Mpurecap}
CMAKE_ARGS+=	-DPERL_EXECUTABLE=${LOCALBASE64}/bin/perl
.endif

.include <bsd.port.post.mk>
