# New ports collection makefile for:	radvd
# Date created:				Fri Jul  6 03:17:33 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	radvd
PORTVERSION=	1.8.3
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.litech.org/radvd/dist/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A Linux/BSD IPv6 router advertisement daemon

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=
USE_GMAKE=	yes
USE_RC_SUBR=	radvd

MAN5=	radvd.conf.5
MAN8=	radvd.8 radvdump.8
PORTDOCS=	CHANGES COPYRIGHT INTRO.html README TODO
PLIST_FILES=	etc/radvd.conf.example sbin/radvd sbin/radvdump

post-install:
	@${INSTALL_DATA} ${WRKSRC}/radvd.conf.example ${PREFIX}/etc/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S.^.${WRKSRC}/.} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
