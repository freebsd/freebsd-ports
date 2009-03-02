# New ports collection makefile for:	pftabled
# Date created:		2006-11-21
# Whom:			Bartlomiej Rutkowski <r@robakdesign.com>
#
# $FreeBSD$
#

PORTNAME=	pftabled
PORTVERSION=	1.07
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.wolfermann.org/

MAINTAINER=	chifeng@gmail.com
COMMENT=	The pftabled is a tool to manage your pf tables remotely

USE_RC_SUBR=	pftabled
MAN1=	pftabled.0

PLIST_FILES=	bin/pftabled-client sbin/pftabled

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

OPTIONS=	PERLC "A Sample Perl Client" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PERLC)
RUN_DEPEND=	p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5
PLIST_FILES+=	bin/pftabled-client.pl

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pftabled-client.pl ${PREFIX}/bin

.endif

post-patch:
	@${REINPLACE_CMD} -e 's|cat1/pftabled.0|man1/pftabled.0|' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
