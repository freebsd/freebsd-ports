# New ports collection makefile for:	Xfstt
# Date created:				11 September 1998
# Whom:					jabley@clear.co.nz
#
# $FreeBSD$
#

PORTNAME=	xfstt
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	x11-servers
MASTER_SITES=	$(MASTER_SITE_SUNSITE)
MASTER_SITE_SUBDIR=	X11/fonts

MAINTAINER=	olgeni@FreeBSD.org

USE_X_PREFIX=	yes
MAN1=		xfstt.1

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/xfstt $(PREFIX)/bin
	$(INSTALL_MAN) $(WRKSRC)/xfstt.1x $(PREFIX)/man/man1/xfstt.1

post-install:
	strip $(PREFIX)/bin/xfstt
	${SED} -e "/%%PREFIX%%/s##${PREFIX}#g" ${FILESDIR}/xfstt.sh \
		> ${PREFIX}/etc/rc.d/xfstt.sh
	${CHMOD} 755 ${PREFIX}/etc/rc.d/xfstt.sh
	$(MKDIR) $(PREFIX)/lib/X11/fonts/TrueType
.if !defined(NOPORTDOCS)
	$(MKDIR) $(PREFIX)/share/doc/xfstt
	$(INSTALL_DATA) $(WRKSRC)/FAQ $(PREFIX)/share/doc/xfstt
	$(INSTALL_DATA) $(WRKSRC)/CHANGES $(PREFIX)/share/doc/xfstt
	$(INSTALL_DATA) $(WRKSRC)/INSTALL $(PREFIX)/share/doc/xfstt
	$(INSTALL_DATA) $(WRKSRC)/THANKS.txt $(PREFIX)/share/doc/xfstt
.endif
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
