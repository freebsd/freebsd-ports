# New ports collection makefile for:	pftabled
# Date created:		2006-11-21
# Whom:			Bartlomiej Rutkowski <r@robakdesign.com>
#
# $FreeBSD$
#

PORTNAME=	pftabled
PORTVERSION=	1.09
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.wolfermann.org/

MAINTAINER=	chifeng@gmail.com
COMMENT=	The pftabled is a tool to manage your pf tables remotely

USE_RC_SUBR=	pftabled
MAN1=		pftabled.0

PLIST_FILES=	bin/pftabled-client sbin/pftabled

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

OPTIONS=	PERLC   "A Sample Perl Client" on \
		PYTHONC "A Sample Python Client" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PERLC)
. if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
. endif
PLIST_FILES+=	bin/pftabled-client.pl
.endif

.if !defined(WITHOUT_PYTHONC)
PLIST_FILES+=	bin/pftabled-client.py
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|cat1/pftabled.0|man1/pftabled.0|' ${WRKSRC}/Makefile.in

post-install:
.if !defined(WITHOUT_PERLC)
	${INSTALL_SCRIPT} ${WRKSRC}/pftabled-client.pl ${PREFIX}/bin/
.endif
.if !defined(WITHOUT_PYTHONC)
	${INSTALL_SCRIPT} ${WRKSRC}/pftabled-client.py ${PREFIX}/bin/
.endif

.include <bsd.port.post.mk>
