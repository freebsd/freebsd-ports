# New ports collection makefile for:	cgiparse
# Date created:				30 March 1997
# Whom:					jmg
#
# $FreeBSD$
#

PORTNAME=	cgiparse
PORTVERSION=	0.9b
CATEGORIES=	www devel
MASTER_SITES=	http://resnet.uoregon.edu/~gurney_j/jmpc/dist/	\
		http://www.funkthat.com/~jmg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library to parse CGI Forms

LIB_DEPENDS=	mime.1:${PORTSDIR}/devel/mime:install

GNU_CONFIGURE=	yes
MAN3=		cgiclose.3 cgigetvalue.3 cginewquerystr.3
INSTALLS_SHLIB=	yes
CFLAGS+=	"-fPIC"

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not link on amd64 (mime port needs to provide libmime.so)"
.endif

post-install:
	${LN} -sf libcgiparse.so.1 ${PREFIX}/lib/libcgiparse.so

.include <bsd.port.post.mk>
