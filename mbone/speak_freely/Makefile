# New ports collection makefile for:    speak_freely
# Original WWW site: http://www.fourmilab.ch/speakfree/unix/index.html
# Version required:     6.1c
# Date created:         18 Apr 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.5 1998/09/22 19:10:14 asami Exp $
#

DISTNAME=       speak_freely-6.1c
CATEGORIES=     mbone audio security
MASTER_SITES=   http://www.fourmilab.ch/speakfree/unix/prior-releases/6.1/

MAINTAINER=     ache@FreeBSD.ORG

LIB_DEPENDS=    gsm.1:${PORTSDIR}/audio/gsm

UTILS=   sfspeaker sfmike sflwl
DEMNS=   sfecho sflwld
DDEMNS=  sfvod
SFLIB=   ${PREFIX}/lib/speak_freely
MAN1=	 ${UTILS:S/$/.1/} ${DEMNS:S/$/.1/} ${DDEMNS:S/$/.1/}

do-install:
	if [ ! -d ${SFLIB} ]; then \
		install -d -o ${BINOWN} -g ${BINGRP} -m 755 ${SFLIB}; \
	fi
	cd ${WRKSRC}; \
	$(INSTALL_DATA) busy.au ring.au ${SFLIB}
	cd ${WRKSRC}; \
	for p in ${UTILS}; do \
		$(INSTALL_PROGRAM) $$p ${PREFIX}/bin; \
		$(INSTALL_MAN) $$p.1 ${PREFIX}/man/man1; \
	done;
	cd ${WRKSRC}; \
	for p in ${DEMNS}; do \
		$(INSTALL_PROGRAM) $$p ${PREFIX}/sbin; \
		$(INSTALL_MAN) $$p.1 ${PREFIX}/man/man1; \
	done;
	cd ${WRKSRC}; \
	for p in ${DDEMNS}; do \
		$(INSTALL_SCRIPT) $$p ${PREFIX}/sbin; \
		$(INSTALL_MAN) $$p.1 ${PREFIX}/man/man1; \
	done;

.include <bsd.port.mk>
