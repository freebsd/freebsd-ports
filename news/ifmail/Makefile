# New ports collection makefile for:    ifmail
# Date created:         19 Feb 1997
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	ifmail
PORTVERSION=	2.15
PORTREVISION=	5
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/fido

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	FidoNet(tm) support package for UN*X platform

MAN3=		parsedate.3
MAN8=		ifmail.8 iftoss.8
IFMAIL_RUNAS?=	ifmail
PLIST_SUB+=	IFMAIL_RUNAS="${IFMAIL_RUNAS}"

pre-configure:
	@${MV} ${WRKSRC}/CONFIG ${WRKSRC}/CONFIG.sed
	${SED} -e "s/OWNER = ifmail/OWNER = ${IFMAIL_RUNAS}/" \
		-e "s#CC = gcc#CC = ${CC}#" \
		-e "s#-O2 -Wall#${CFLAGS} -DHAS_STDARG_H -Wall#" \
		${WRKSRC}/CONFIG.sed > ${WRKSRC}/CONFIG

pre-install:
	if ! pw usershow ${IFMAIL_RUNAS}; then pw useradd ${IFMAIL_RUNAS} -g uucp -u 75 \
		-h - -d /nonexistent -s /nonexistent -c "Ifmail Server"; fi
	${MKDIR} ${PREFIX}/libexec/ifmail

post-install:
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/ifgate/${i} ${PREFIX}/man/man8
.endfor
.for i in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/iflib/${i} ${PREFIX}/man/man3
.endfor
	@${ECHO_CMD} "updating ${DESTDIR}/etc/services"
	@${CP} ${DESTDIR}/etc/services ${DESTDIR}/etc/services.bak
	@(grep -v ^ifcico ${DESTDIR}/etc/services.bak; \
	${ECHO_CMD} "ifcico		60179/tcp  #ifcico server (ifmail)") \
		> ${DESTDIR}/etc/services
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.for i in ifcico ifgate iflib
	${INSTALL_DATA} ${WRKSRC}/${i}/README ${DOCSDIR}/README.${i}
.endfor
	${MKDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/misc -cf - . | ${TAR} -C ${EXAMPLESDIR} -xf -
.endif

.include <bsd.port.mk>
