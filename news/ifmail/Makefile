# New ports collection makefile for:    ifmail
# Date created:         19 Feb 1997
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	ifmail
PORTVERSION=	2.15
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/fido

MAINTAINER=	dinoex@FreeBSD.org

MAN3=		parsedate.3
MAN8=		ifmail.8 iftoss.8

.if defined(IFMAIL_RUNAS)
pre-configure:
	@${PERL5} -pi -e "s/OWNER = ifmail/OWNER = ${IFMAIL_RUNAS}/" \
		${WRKSRC}/CONFIG
.endif

pre-install:
.if !defined(IFMAIL_RUNAS)
	if ! pw usershow ifmail; then pw useradd ifmail -g uucp -u 70 \
		-h - -d /nonexistent -s /nonexistent -c "Ifmail Server"; fi
.endif
	${MKDIR} ${PREFIX}/libexec/ifmail

post-install:
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/ifgate/${i} ${PREFIX}/man/man8
.endfor
.for i in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/iflib/${i} ${PREFIX}/man/man3
.endfor
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
