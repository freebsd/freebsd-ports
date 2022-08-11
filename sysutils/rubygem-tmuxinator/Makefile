PORTNAME=	tmuxinator
PORTVERSION=	3.0.5
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Manage complex tmux sessions easily

LICENSE=	MIT

RUN_DEPENDS=	rubygem-erubis>=2.6<3:www/rubygem-erubis \
		rubygem-thor>=1.2.1<1.3:devel/rubygem-thor \
		rubygem-xdg2>=2.2.5<3:devel/rubygem-xdg2

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/tmuxinator \
		etc/bash_completion.d/_tmuxinator.bash \
		share/zsh/site-functions/_tmuxinator

OPTIONS_SINGLE=	TMUX
OPTIONS_SINGLE_TMUX=	TMUX TMUX23
OPTIONS_DEFAULT=TMUX

TMUX_DESC=	Use tmux from sysutils/tmux
TMUX23_DESC=	Use tmux from sysutils/tmux23

TMUX_RUN_DEPENDS=	tmux:sysutils/tmux
TMUX23_RUN_DEPENDS=	tmux:sysutils/tmux23

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completion/tmuxinator.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/_tmuxinator.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completion/tmuxinator.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_tmuxinator

.include <bsd.port.mk>
