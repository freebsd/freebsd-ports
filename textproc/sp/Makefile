# New ports collection makefile for:	sp
# Date created:		April 26, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

PORTNAME=	sp
PORTVERSION=	1.3.4
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/sp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An object-oriented toolkit for SGML parsing and entity management

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.if ${MACHINE_ARCH} == sparc64
BROKEN=		does not compile on ${MACHINE_ARCH}
.endif

USE_SUBMAKE=	yes
INSTALLS_SHLIB=	yes

post-install:
	$(MKDIR) $(PREFIX)/include/sp
	$(MKDIR) $(PREFIX)/share/doc/sp
	$(RM) -f $(WRKSRC)/include/*.orig
	for file in $(WRKSRC)/include/*;do $(INSTALL_DATA) $$file $(PREFIX)/include/sp;done
	for file in $(WRKSRC)/doc/*;do $(INSTALL_DATA) $$file $(PREFIX)/share/doc/sp;done

.include <bsd.port.post.mk>
