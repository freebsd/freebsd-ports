# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tmuxinator
PORTVERSION=	0.9.0
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Manage complex tmux sessions easily

LICENSE=	MIT

RUN_DEPENDS=	rubygem-erubis>=2.6:www/rubygem-erubis \
		rubygem-thor>=0.15.0:devel/rubygem-thor \
		tmux:sysutils/tmux

USES=		gem
USE_RUBY=	yes
NO_ARCH=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completion/tmuxinator.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/_tmuxinator.bash

	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completion/tmuxinator.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_tmuxinator

.include <bsd.port.mk>
