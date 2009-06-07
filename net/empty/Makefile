# New ports collection makefile for:	empty
# Date created:		17 September 2005
# Whom:			Mikhail Zakharov <zmey20000@yahoo.com>
#
# $FreeBSD$

PORTNAME=	empty
PORTVERSION=	0.6.17b
CATEGORIES=	net
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	zmey20000@yahoo.com
COMMENT=	Expect-like tool for pure shell

MAN1=		empty.1
DOCS=		CHANGELOG COPYRIGHT README README.CYGWIN
EXAMPLES=	README em_ssh.sh em_ssh_2.sh em_sh.sh \
		em_telnet.sh em_telnet_2.sh emsu.sh runtests.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/empty ${PREFIX}/bin/
	@${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/,} ${MAN1PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/examples/,} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
