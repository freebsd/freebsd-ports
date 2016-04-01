# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GStreamer
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	multimedia perl5
MASTER_SITES=	SF/gtk2-perl/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Set of Perl5 bindings for gstreamer

BUILD_DEPENDS=	p5-Glib2>=1.101:devel/p5-Glib2 \
		p5-ExtUtils-Depends>=0.205:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.07:devel/p5-ExtUtils-PkgConfig
RUN_DEPENDS=	p5-Glib2>=1.101:devel/p5-Glib2 \
		p5-ExtUtils-Depends>=0.205:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.07:devel/p5-ExtUtils-PkgConfig

USES=		gmake perl5
USE_GSTREAMER=	yes
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if exists(${PERL})
PERL_THREADED!=	${PERL} -mthreads -e '' >/dev/null 2>&1 && ${ECHO_CMD} 'yes' || ${ECHO_CMD}
.if ${PERL_THREADED} == ""
IGNORE=		must be built with a threaded Perl, reinstall Perl with the THREADS option on
.endif
.endif

.include <bsd.port.post.mk>
