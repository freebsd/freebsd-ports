NUGET_DISTSUBDIR?=	nuget
EXTRACT_ONLY?=		${_DISTFILES:N${_NUPKG_PREFIX}*.nupkg}

NUGET_MASTER_SITES=	https://api.nuget.org/v3-flatcontainer/%LCNAME%/%VERSION%/%LCNAME%.%VERSION%.nupkg?dummy=/
PWSH_MASTER_SITES=	https://www.powershellgallery.com/api/v2/package/%NAME%/%VERSION%/?dummy=/

_NUGET2TUPLE_CMD=	nuget2tuple

# Automatic runtime package inclusion is disabled due to Make parsing issues
# with package names containing hyphens. Port maintainers should add these
# packages manually to Makefile.nuget:
#   Microsoft.NETCore.App.Runtime.linux-x64:VERSION
#   Microsoft.AspNetCore.App.Runtime.linux-x64:VERSION
#   Microsoft.NETCore.App.Host.linux-x64:VERSION

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

# Generates NUGET_NUPKGS= ... line ready to be pasted into the port based on
# .csproj/.fsproj files found in ${WRKSRC}
make-nuget-tuple: check-nuget2tuple
	@${ECHO_MSG} "===> Processing .NET project files"
	${_NUGET2TUPLE_CMD} ${WRKSRC}

check-nuget2tuple:
	@if ! type ${_NUGET2TUPLE_CMD} > /dev/null 2>&1; then \
		${ECHO_MSG} "===> nuget2tuple executable not found, install \"ports-mgmt/nuget2tuple\""; exit 1; \
	fi
