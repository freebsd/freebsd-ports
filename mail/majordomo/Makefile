# New ports collection makefile for:	majordomo
# Date created:		23 October 1996
# Whom:			jfitz@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	majordomo
PORTVERSION=	1.94.5
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		ftp://ftp.sgi.com/other/majordomo/1.94.5/ \
		ftp://ftp.greatcircle.com/pub/majordomo/1.94.5/
EXTRACT_SUFX=   .tgz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	A mailing list manager

.if defined(WITH_SHA1_COOKIES)
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
.else
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
.endif

USE_PERL5=	yes

# Needs to create a user and group
IS_INTERACTIVE= yes
NO_PACKAGE=	"User and group need to be created"
ALL_TARGET=	wrapper
INSTALL_TARGET=	install install-wrapper
MAN1=		approve.1 bounce-remind.1 digest.1
MAN8=		majordomo.8

post-patch:
.if defined(WITH_POSTFIX_APPROVE_PATCH)
	@cd ${WRKSRC} && ${PATCH} < ${FILESDIR}/postfix-approve-patch 2>/dev/null
.endif
.if defined(WITH_SHA1_COOKIES)
	${REINPLACE_CMD} \
		-e 's,md5_hex,sha1_hex,g' \
		-e 's,Digest::MD5,Digest::SHA1,g' \
		${WRKSRC}/majordomo
.endif
	${FIND} ${WRKSRC} -type f \
	    -exec ${REINPLACE_CMD} \
		-e 's,/etc/majordomo.cf,${PREFIX}/etc/majordomo.cf,g' {} \;
	${FIND} ${WRKSRC} -name *.orig -delete
	${FIND} ${WRKSRC} -name *.bak -delete


pre-configure:
	@ ${SETENV} ${MAKE_ENV} ${PERL} ${SCRIPTDIR}/createuser
	@ ${CP} ${FILESDIR}/aliases.majordomo ${WRKSRC}

pre-install:
	@ if ${TEST} -f ${WRKSRC}/majordomo.cf; then :; else \
		${CP} ${WRKSRC}/sample.cf ${WRKSRC}/majordomo.cf; \
		${PERL} ${SCRIPTDIR}/makeseed ${WRKSRC}/majordomo.cf; \
	fi

post-install:
.for file in ${MAN1}
	@ ${INSTALL_MAN} ${WRKSRC}/Doc/man/${file} ${PREFIX}/man/man1
.endfor
.for file in ${MAN8}
	@ ${INSTALL_MAN} ${WRKSRC}/Doc/man/${file} ${PREFIX}/man/man8
.endfor

		@ ${LN} -sf archive2.pl ${PREFIX}/majordomo/archive
		@ for dir in tmp lists/test-l.archive lists/test-l-digest.archive digests/test-l-digest doc; do \
			${MKDIR} ${PREFIX}/majordomo/$$dir; \
		done
		@ ${CHOWN} majordom:majordom ${PREFIX}/majordomo/tmp
		@ ${CHMOD} 700 ${PREFIX}/majordomo/tmp
		@ ${CHMOD} 755 ${PREFIX}/majordomo
		@ for dir in digests lists lists/test-l.archive lists/test-l-digest.archive digests/test-l-digest doc; do \
			${CHOWN} majordom:majordom ${PREFIX}/majordomo/$$dir; \
			${CHMOD} 775 ${PREFIX}/majordomo/$$dir; \
		done
.if !defined(NOPORTDOCS)
		@ for f in Changelog FUTURE INSTALL LICENSE NEWLIST README; do \
			${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/majordomo/doc; \
		done
		@ for f in FAQ README.sequencer list-owner-info majordomo-faq.html majordomo.lisa6.ps majordomo.ora; do \
			${INSTALL_DATA} ${WRKSRC}/Doc/$$f ${PREFIX}/majordomo/doc; \
		done
		@ ${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/majordomo/doc
.endif
		@ if test -f ${PREFIX}/majordomo/aliases.majordomo; then :; \
			else ${INSTALL_DATA} ${WRKSRC}/aliases.majordomo \
			${PREFIX}/majordomo; fi
		@ for f in test-l test-l-digest test-l.passwd test-l.info; do \
			${INSTALL_DATA} ${FILESDIR}/$$f ${PREFIX}/majordomo/lists; \
		done
		@ ${LN} -sf test-l.info ${PREFIX}/majordomo/lists/test-l-digest.info
		@ ${LN} -sf test-l.passwd ${PREFIX}/majordomo/lists/test-l-digest.passwd
		@ ${CHMOD} 660 ${PREFIX}/majordomo/lists/test-l.passwd
		@ ${CHOWN} -R majordom:majordom ${PREFIX}/majordomo/lists
		@ ${CHMOD} -R 664 ${PREFIX}/majordomo/lists
		@ ${CHMOD} 755 ${PREFIX}/majordomo/lists
		@ ${CHMOD} 755 ${PREFIX}/majordomo/lists/test-l.archive
		@ ${CHMOD} 755 ${PREFIX}/majordomo/lists/test-l-digest.archive
		@ ${CHMOD} 660 ${PREFIX}/majordomo/lists/*.passwd
.if !defined(BATCH)
		@ ${SH} ${SCRIPTDIR}/adaptwrapper ${PREFIX}
		@ /usr/bin/more -e ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.mk>
