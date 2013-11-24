# Created by: jfitz@FreeBSD.org
# $FreeBSD$

PORTNAME=	majordomo
PORTVERSION=	1.94.5
PORTREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		ftp://ftp.sgi.com/other/majordomo/1.94.5/ \
		ftp://ftp.greatcircle.com/pub/majordomo/1.94.5/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	A mailing list manager

USES=		shebangfix perl5

SHEBANG_FILES=	contrib/sequencer

ALL_TARGET=	wrapper
INSTALL_TARGET=	install install-wrapper
MAN1=		approve.1 bounce-remind.1 digest.1
MAN8=		majordomo.8
PKGMESSAGE=	${FILESDIR}/post-install-notes

DOCSDIR=	${PREFIX}/${PORTNAME}/doc

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-fetch:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	${DIALOG} --yesno "WARNING: Majordomo is a really old mail list manager. The last version was released in january 2000, and there does not seem to be any updates coming. You might want to consider using mailman instead. Are you sure you want to install majordomo?" 8 70 || ${FALSE}
.endif

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
	@ ${SH} ${PKGINSTALL} ${PKGNAME} ADDUSER
	@ ${CP} ${FILESDIR}/aliases.majordomo ${WRKSRC}

post-configure:
	@ if ${TEST} -f ${WRKSRC}/majordomo.cf; then :; else \
		${CP} ${WRKSRC}/sample.cf ${WRKSRC}/majordomo.cf; \
		${PERL} ${SCRIPTDIR}/makeseed ${WRKSRC}/majordomo.cf; \
	fi

post-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} NOPORTDOCS=${NOPORTDOCS} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.for file in ${MAN1}
	@ ${INSTALL_MAN} ${WRKSRC}/Doc/man/${file} ${PREFIX}/man/man1
.endfor
.for file in ${MAN8}
	@ ${INSTALL_MAN} ${WRKSRC}/Doc/man/${file} ${PREFIX}/man/man8
.endfor
	@ ${LN} -sf archive2.pl ${PREFIX}/majordomo/archive
.if !defined(NOPORTDOCS)
	 for f in Changelog FUTURE INSTALL LICENSE NEWLIST README; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
	 for f in FAQ README.sequencer list-owner-info majordomo-faq.html majordomo.lisa6.ps majordomo.ora; do \
		${INSTALL_DATA} ${WRKSRC}/Doc/$$f ${DOCSDIR}; \
	done
	 ${INSTALL_DATA} ${FILESDIR}/post-install-notes ${DOCSDIR}
.endif
	@ ${INSTALL_DATA} ${WRKSRC}/aliases.majordomo \
		${PREFIX}/majordomo/aliases.majordomo-sample
	@ for f in test-l.passwd test-l.info; do \
		${INSTALL_DATA} ${FILESDIR}/$$f ${PREFIX}/majordomo/lists; \
	done
	@ for f in test-l test-l-digest; do \
		${TOUCH} ${PREFIX}/majordomo/lists/$$f; \
		${CHMOD} 644 ${PREFIX}/majordomo/lists/$$f; \
	done
	@ ${LN} -sf test-l.info ${PREFIX}/majordomo/lists/test-l-digest.info
	@ ${LN} -sf test-l.passwd ${PREFIX}/majordomo/lists/test-l-digest.passwd
	@ ${CHOWN} -R majordom:majordom ${PREFIX}/majordomo
	@ ${CHMOD} -R 644 ${PREFIX}/majordomo/lists
	@ ${CHMOD} 755 ${PREFIX}/majordomo/lists
	@ ${CHMOD} 755 ${PREFIX}/majordomo/lists/*.archive
	@ ${CHMOD} 660 ${PREFIX}/majordomo/lists/*.passwd
.if !defined(BATCH)
	@ ${SH} ${SCRIPTDIR}/adaptwrapper ${PREFIX}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
