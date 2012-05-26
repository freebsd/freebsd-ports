# New ports collection makefile for:	mosh
# Date created:				10 Apr 2012
# Whom:					Ryan Steinmetz <zi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mosh
PORTVERSION=	1.2.1
CATEGORIES=	net
MASTER_SITES=	http://cloud.github.com/downloads/keithw/${PORTNAME}/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A mobile terminal that supports intermittant connectivity

LICENSE=	GPLv3

LIB_DEPENDS=	protobuf.7:${PORTSDIR}/devel/protobuf
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/IO/Pty.pm:${PORTSDIR}/devel/p5-IO-Tty

USE_PERL5_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-utempter
INSTALL_TARGET=	install-strip

LATEST_LINK=	mosh-term

CONFLICTS_INSTALL=	mosh-0.[2-9].*

PLIST_FILES=	bin/mosh bin/mosh-server bin/mosh-client
MAN1=		mosh-client.1 mosh-server.1 mosh.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900004
LIB_DEPENDS+=	utempter.0:${PORTSDIR}/sysutils/libutempter
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
