# New ports collection makefile for:	majordomo
# Version required:	1.94
# Date created:		23 October 1996
# Whom:			jfitz@FreeBSD.ORG
#
# $Id: Makefile,v 1.1.1.1 1996/07/20 01:39:21 asami Exp $
#

DISTNAME=	majordomo-1.94
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.greatcircle.com/pub/majordomo/ \
		ftp://ftp.sgi.com/other/majordomo/ \
		ftp://ftp-europe.sgi.com/other/majordomo/

EXTRACT_SUFX=   .tar.Z

MAINTAINER=	jfitz@FreeBSD.ORG

# Needs to create a user and group
IS_INTERACTIVE= yes
NO_PACKAGE=	yes

ALL_TARGET=	wrapper
INSTALL_TARGET=	install install-wrapper

pre-configure:
		@ ${SETENV} ${MAKE_ENV} /usr/bin/perl ${SCRIPTDIR}/createuser
		@ ${CP} ${FILESDIR}/aliases.majordomo ${WRKSRC}

pre-install:
		@ ${CP} ${WRKSRC}/sample.cf ${WRKSRC}/majordomo.cf

post-install:
		@ ln -sf ${PREFIX}/majordomo/Tools/digest ${PREFIX}/majordomo
		@ for dir in tmp lists/test-l.archive lists/test-l-digest.archive digests/test-l-digest doc; do \
			${MKDIR} -p ${PREFIX}/majordomo/$$dir; \
		done
		@ /usr/sbin/chown majordom.majordom ${PREFIX}/majordomo/tmp
		@ /bin/chmod 700 ${PREFIX}/majordomo/tmp
		@ /bin/chmod 755 ${PREFIX}/majordomo
		@ for dir in digests lists lists/test-l.archive lists/test-l-digest.archive digests/test-l-digest doc; do \
			/usr/sbin/chown majordom.majordom ${PREFIX}/majordomo/$$dir; \
			/bin/chmod 775 ${PREFIX}/majordomo/$$dir; \
		done
.if !defined(NOPORTDOCS)
		@ for file in Changelog FUTURE INSTALL LICENSE NEWLIST README; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/majordomo/doc; \
		done
		@ for file in FAQ README.sequencer list-owner-info majordomo-faq.html majordomo.lisa6.ps majordomo.ora; do \
			${INSTALL_DATA} ${WRKSRC}/Doc/$$file ${PREFIX}/majordomo/doc; \
		done
		@ ${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/majordomo/doc
.endif
		@ ${INSTALL_DATA} ${WRKSRC}/aliases.majordomo ${PREFIX}/majordomo
		@ for file in test-l test-l-digest test-l.passwd test-l.info; do \
			${INSTALL_DATA} ${FILESDIR}/$$file ${PREFIX}/majordomo/lists; \
		done
		@ ln -sf ${PREFIX}/majordomo/lists/test-l.info ${PREFIX}/majordomo/lists/test-l-digest.info
		@ ln -sf ${PREFIX}/majordomo/lists/test-l.passwd ${PREFIX}/majordomo/lists/test-l-digest.passwd
		@ /bin/chmod 660 ${PREFIX}/majordomo/lists/test-l.passwd
.if !defined(NOMANCOMPRESS)
		@ for file in approve bounce-remind digest; do \
			gzip -9nf ${PREFIX}/man/man1/$$file.1; \
		done
		@ gzip -9nf ${PREFIX}/man/man8/majordomo.8
.endif
		@ /usr/sbin/chown -R majordom.majordom ${PREFIX}/majordomo/lists
		@ /bin/chmod -R 664 ${PREFIX}/majordomo/lists
		@ /bin/chmod 775 ${PREFIX}/majordomo/lists
		@ /bin/chmod 775 ${PREFIX}/majordomo/lists/test-l.archive
		@ /bin/chmod 775 ${PREFIX}/majordomo/lists/test-l-digest.archive
		@ /bin/chmod 660 ${PREFIX}/majordomo/lists/*.passwd
.if !defined(BATCH)
		@ /usr/bin/more -e ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.mk>
