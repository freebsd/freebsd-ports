# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tmuxinator
PORTVERSION=	0.14.0
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Manage complex tmux sessions easily

LICENSE=	MIT

RUN_DEPENDS=	rubygem-erubis>=2.6:www/rubygem-erubis \
		rubygem-thor>=0.15.0:devel/rubygem-thor \
		rubygem-xdg>=2.2.3:devel/rubygem-xdg

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

OPTIONS_DEFAULT=	TMUX
OPTIONS_SINGLE=		TMUX
OPTIONS_SINGLE_TMUX=	TMUX TMUX23

TMUX_DESC=		Enable tmux
TMUX23_DESC=		Enable tmux23

TMUX_RUN_DEPENDS=	tmux:sysutils/tmux
TMUX23_RUN_DEPENDS=	tmux:sysutils/tmux23

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completion/tmuxinator.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/_tmuxinator.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completion/tmuxinator.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_tmuxinator

.include <bsd.port.mk>
