PORTNAME=	pizauth
DISTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	mail

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Command-line OAuth2 authentication daemon
WWW=		https://tratt.net/laurie/src/pizauth/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ltratt
GH_TAGNAME=	${DISTNAME}

RUSTFLAGS=	${ARCH:S/i386/YES/:C/^[a-z].*//:S/YES/-C target-feature=+sse,+sse2/} # add sse sse2 target-features only on i386

PLIST_FILES=	bin/pizauth \
		share/man/man1/pizauth.1.gz \
		share/man/man5/pizauth.conf.5.gz

post-install:
	(cd ${WRKSRC} && \
		${INSTALL_MAN} pizauth.1 ${STAGEDIR}${PREFIX}/share/man/man1/ && \
		${INSTALL_MAN} pizauth.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5/)

.include <bsd.port.mk>
