# New ports collection makefile for:	jailkit
# Date created:		2009-08-20
# Whom:			Sylvio Cesar <scjamorim@bsd.com.br>
#
# $FreeBSD$
#

PORTNAME=	jailkit
PORTVERSION=	2.8
CATEGORIES=	shells
MASTER_SITES=	http://olivier.sessink.nl/jailkit/ \
		http://www.sfr-fresh.com/unix/privat/

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Jailkit is a set of utilities to limit user account

GNU_CONFIGURE=	yes
USE_PYTHON=	2.4+

SHELLS=		/etc/shells

MAN8=		jailkit.8 \
		jk_addjailuser.8 \
		jk_check.8 \
		jk_chrootlaunch.8 \
		jk_chrootsh.8 \
		jk_cp.8 \
		jk_init.8 \
		jk_jailuser.8 \
		jk_list.8 \
		jk_lsh.8 \
		jk_socketd.8 \
		jk_uchroot.8 \
		jk_update.8
MANCOMPRESSED=	yes

PORTDOCS=	COPYRIGHT README.txt

post-install:
	@${ECHO_MSG} "Updating ${SHELLS}"
	@${CP} ${SHELLS} ${SHELLS}.bak
	@(${GREP} -v ${PREFIX}/sbin/jk_chrootsh ${SHELLS}.bak; \
	  ${ECHO_CMD} ${PREFIX}/sbin/jk_chrootsh) > ${SHELLS}
	@${RM} -f ${SHELLS}.bak

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif
.include <bsd.port.mk>
