# New ports collection makefile for:	micq
# Date created:				11 Oct 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	micq
PORTVERSION=	0.4.6.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=   http://micq.ukeer.de/source/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/1/p1/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@freebsd.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.1/-p1/}/src

MAN1=		micq.1

SUP_LANGS=	`${SED} 's|$$|,|' < ${FILESDIR}/slangs`

pre-configure:
.if !defined(WITH_MICQ_LANG)
	@${ECHO_MSG} "If you want to compile ${PORTNAME} with your native"
	@${ECHO_MSG} "language support:"
	@${ECHO_MSG} "make WITH_MICQ_LANG=<your_lang>"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Currently supported <your_lang> values are:"
	@${ECHO} "  "${SUP_LANGS} | ${SED} 's|,$$|.|' | /usr/bin/fmt
.else
	@/usr/bin/printf "#define ${WITH_MICQ_LANG}_LANG\n#undef ENGLISH_LANG" >> \
		${WRKSRC}/../include/config.h
	@${ECHO_MSG} "Compiling ${PORTNAME} with ${WITH_MICQ_LANG}."
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../micq.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/micq
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/micq
	${INSTALL_DATA} ${WRKSRC}/../CHANGELOG ${PREFIX}/share/doc/micq
.endif

# Administrative rule to automatically extract
# names of supported langs
update-slangs: patch
	${GREP} '#define .*_LANG' < ${WRKSRC}/../include/config.h | \
		${SED} 's|.*#define || ; s|_LANG.*||' | /usr/bin/sort | \
		/usr/bin/uniq > ${FILESDIR}/slangs

.include <bsd.port.mk>
