# New ports collection makefile for:	zsh
# Date created:			11 Feb. 1995
# Whom:				torstenb
#
# $FreeBSD$
#

PORTNAME=	zsh
PORTVERSION=	3.0.8
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.sterling.com/zsh/ \
		ftp://ftp.rge.com/pub/shells/zsh/ \
		ftp://ftp.cenatls.cena.dgac.fr/pub/shells/zsh/ \
		ftp://ftp.fu-berlin.de/pub/unix/shells/zsh/ \
		ftp://ftp.ips.oz.au/pub/packages/zsh/ \
		ftp://ftp.uit.no/pub/unix/shells/zsh/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	will@FreeBSD.org

GNU_CONFIGURE=	yes
MAN1=		zsh.1 zshbuiltins.1 zshcompctl.1 zshexpn.1 zshmisc.1 \
		zshoptions.1 zshall.1 zshparam.1 zshzle.1
PLIST_SUB=	ZSH_VERSION=${DISTNAME:S/zsh-//}

.if defined(WANT_STATIC)
CONFIGURE_ENV+=	"LDFLAGS=-static"
.endif

post-build:
# Fix ".so" macro problem by using "soelim" command.
	@(cd ${WRKSRC} ; \
		${LN} -sf ./Doc man1 ; \
		if [ ! -f ./man1/zshall.1.source ]; then \
			${MV} -f ./man1/zshall.1 ./man1/zshall.1.source ; \
		fi ; \
		${RM} -f ./man1/zshall.1 ; \
		/usr/bin/soelim ./man1/zshall.1.source > ./man1/zshall.1 ; \
	)

post-install:
	@install-info ${PREFIX}/info/zsh.info ${PREFIX}/info/dir
	@${ECHO} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/zsh /etc/shells.bak; \
	  ${ECHO} ${PREFIX}/bin/zsh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
