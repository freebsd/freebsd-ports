NUGET_DISTSUBDIR?=	nuget
EXTRACT_ONLY?=		${_DISTFILES:N${_NUPKG_PREFIX}*.nupkg}

NUGET_MASTER_SITES=	https://api.nuget.org/v3-flatcontainer/%LCNAME%/%VERSION%/%LCNAME%.%VERSION%.nupkg?dummy=/
PWSH_MASTER_SITES=	https://www.powershellgallery.com/api/v2/package/%NAME%/%VERSION%/?dummy=/

.for nugrp in ${NUGET_GROUPS}
.  for pkg in ${${nugrp}_NUPKGS:O}
.    for name version in ${pkg:S/:/ /g}
.      for group in nupkg_${name:S/./_/g:S/-/_/g}_${version:S/.//g:S/-//g}
MASTER_SITES+=	${${nugrp}_MASTER_SITES:S/%NAME%/${name}/g:S/%LCNAME%/${name:tl}/g:S/%VERSION%/${version}/g}:${group}
DISTFILES+=	${NUGET_DISTSUBDIR}/${name:tl}.${version:tl}.nupkg:${group}
.      endfor
.    endfor
.  endfor
.endfor
