# New ports collection makefile for:	perlsh
# Version required:	0.004pre2
# Date created:		11 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	psh-0.004pre2
CATEGORIES=	shells
MASTER_SITES=	http://www.focusresearch.com/gregor/psh/

MAINTAINER=	andrews@technologist.com

do-build:
	@(cd ${WRKSRC} && ${PERL} Makefile.PL && ${MAKE})

post-build:
	@${PERL} -pi -e "s/\/usr\/local\/bin\/perl/\/usr\/bin\/perl/g" ${WRKSRC}/psh

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/perlsh
.for DOC in CHANGES MANIFEST README TODO psh.NEWS pshrc test.pl psh.pod
	@${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/perlsh
.endfor
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/psh ${PREFIX}/bin

post-install:   
	@${ECHO} "Updating /etc/shells" 
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/psh /etc/shells.bak; \
	${ECHO} ${PREFIX}/bin/psh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
