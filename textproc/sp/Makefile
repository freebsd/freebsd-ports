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

MAINTAINER=	chuckr@FreeBSD.org

USE_SUBMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
BROKEN=		"Does not compile on 5.0"
.endif

post-patch:
	$(CP) $(WRKSRC)/Makefile $(WRKSRC)/Makefile.sed
	$(CP) $(WRKSRC)/Makefile.lib $(WRKSRC)/Makefile.lib.sed
	$(SED) -e "s%/opt/local%$(PREFIX)%" <$(WRKSRC)/Makefile.sed >$(WRKSRC)/Makefile
	$(SED) -e "s%/opt/local%$(PREFIX)%" <$(WRKSRC)/Makefile.lib.sed >$(WRKSRC)/Makefile.lib

post-install:
	$(MKDIR) $(PREFIX)/include/sp
	$(MKDIR) $(PREFIX)/share/doc/sp
	$(RM) -f $(WRKSRC)/include/*.orig
	for file in $(WRKSRC)/include/*;do $(INSTALL_DATA) $$file $(PREFIX)/include/sp;done
	for file in $(WRKSRC)/doc/*;do $(INSTALL_DATA) $$file $(PREFIX)/share/doc/sp;done

.include <bsd.port.post.mk>
