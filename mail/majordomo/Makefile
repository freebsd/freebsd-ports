# New ports collection makefile for:	majordomo
# Version required:	1.94.4
# Date created:		23 October 1996
# Whom:			jfitz@FreeBSD.ORG
#
# $Id: Makefile,v 1.10 1997/04/29 10:55:56 jfitz Exp $
#

DISTNAME=	majordomo-1.94.4
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sgi.com/other/majordomo/1.94.4/ \
		ftp://ftp-europe.sgi.com/other/majordomo/1.94.4/
#		ftp://ftp.greatcircle.com/pub/majordomo/1.94.3/ \
EXTRACT_SUFX=   .tgz

MAINTAINER=	jfitz@FreeBSD.ORG

# Needs to create a user and group
IS_INTERACTIVE= yes
NO_PACKAGE=	"User and group need to be created"
ALL_TARGET=	wrapper
INSTALL_TARGET=	install install-wrapper
MAN1=		approve.1 bounce-remind.1 digest.1
MAN8=		majordomo.8

pre-configure:
		@ ${SETENV} ${MAKE_ENV} /usr/bin/perl ${SCRIPTDIR}/createuser
		@ ${CP} ${FILESDIR}/aliases.majordomo ${WRKSRC}

pre-install:
		@ ${CP} ${WRKSRC}/sample.cf ${WRKSRC}/majordomo.cf

post-install:
		@ ln -sf archive2.pl ${PREFIX}/majordomo/archive
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
		@ ln -sf test-l.info ${PREFIX}/majordomo/lists/test-l-digest.info
		@ ln -sf test-l.passwd ${PREFIX}/majordomo/lists/test-l-digest.passwd
		@ /bin/chmod 660 ${PREFIX}/majordomo/lists/test-l.passwd
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
