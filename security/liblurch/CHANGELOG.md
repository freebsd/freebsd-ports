# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.7.0] - 2021-02-12
### Added
- This file.
- An API reachable through _libpurple_ signals. See `lurch_api.h` for details and usage.
- Testing setup using _cmocka_ and tests for new modules.
- CI setup running the tests in _appveyor_ and reporting coverage results to _codecov_.
- The possibility to dynamically link against the submodule libaries. ([#151](https://github.com/gkdr/lurch/pull/151)) (thanks, [@fortysixandtwo](https://github.com/fortysixandtwo)!)

### Changed
- A new `/command` handler using the API, replacing the old implementation. The commands are a bit different and some are new.
- Updated _libomemo_ submodule to 0.7.1. See the [changelog](https://github.com/gkdr/libomemo/blob/master/CHANGELOG.md) for details.
- Updated _axc_ submodule to 0.3.4. See the [changelog](https://github.com/gkdr/axc/blob/master/CHANGELOG.md) for details.

### Removed
- The `lurch_initialised` setting in the `accounts.xml`.

### Fixed
- Warnings are no longer displayed at level "error".
- Use constants instead of magic numbers for conversation type checks.
- Some forgotten module name parameters for libpurple logging functions.
- Report skipped messages in conversation window and not just the debug log. ([#150](https://github.com/gkdr/lurch/pull/150)) (thanks, [@agx](https://github.com/agx)!)
- Failing tests on certain platforms. ([#153](https://github.com/gkdr/lurch/pull/153)) (thanks, [@agx](https://github.com/agx)!)
- Format the DB filenames in the README as code so they're not rendered as `mailto:` links. ([#130](https://github.com/gkdr/lurch/pull/130)) (thanks, [@msiism](https://github.com/msiism)!)
- Some memory handling improvements. ([#160](https://github.com/gkdr/lurch/pull/160), [#161](https://github.com/gkdr/lurch/pull/161)) (thanks, [@root-hardenedvault](https://github.com/root-hardenedvault)!)

## [0.6.8] and below
Lost to git commit logs and GitHub releases page.
